#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct s1{
	int l,r;
};
s1 s[500005];
int t;
bool flag[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=0,flag2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=1;
		}
		if(a[i]>=2){
			flag2=1;
		}
	}
	if(flag1==0){
		cout<<n/2;
	}else if(flag2==0){
		int h=0;
		if(k==0){
			for(int i=1;i<=n;){
				if(a[i]==0){
					h++;
					i+=1;
				}else if(a[i]==1&&a[i+1]==1&&i+1<=n){
					h++;
					i+=2;
				}else{
					i+=1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					h++;
				}
			}
		}
		cout<<h;
	}else{
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int j=i;j<=n;j++){
				if(j==i){
					if(x==k){
						t++;
						s[t].l=i;
						s[t].r=j;
						break;
					}
				}else{
					int xx=a[j],ans=0;
					int cheng=1;
					while(x>0||xx>0){
						int aa=x%2,bb=xx%2;
						x/=2;
						xx/=2;
						if((aa+bb)%2==1){
							ans+=cheng;
						}
						cheng=cheng*2;
					}
					x=ans;
					if(x==k){
						t++;
						s[t].l=i;
						s[t].r=j;
						break;
					}
				}
			}
		}
		for(int i=1;i<t;i++){
			if(flag[i]==0){
				int h=0,x=0;
				bool flag3=0;
				for(int j=i+1;j<=t;j++){
					if(flag[j]==0){
						if(s[i].r>=s[j].l){
							h++;
							if(flag3==0){
								x=j;
								flag3=1;
							}
						}
					}
				}
				if(h==1){
					t--;
					flag[x]=1;
				}else if(h>=2){
					t--;
					flag[i]=0;
				}
			}
		}
		cout<<t;
	}
	return 0;
} 
