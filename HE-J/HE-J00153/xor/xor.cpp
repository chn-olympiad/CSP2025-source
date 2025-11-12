#include<iostream>
using namespace std;
int cm(int a,int b){
	int a1[100000];
	int b1[100000];
	int ans1[100000];
	int y=0,x=0;
	int s=a;
	while(s>0){
		a1[y]=s%2;
		y++;
		s/=2;
	}
	s=b;
	while(s>0){
		b1[x]=s%2;
		x++;
		s/=2;
	}
	if(x>y){
		int p=y;
		for(int i=0;i<=x-y;i++){
			a1[y]=0;
			y++;
		}
	}else if(x<y){
		int p=x;
		for(int i=0;i<=y-x;i++){
			b1[x]=0;
			x++;
		}
	}
	for(int i=0;i<x;i++){
		if(a1[i]==b1[i]){
			ans1[i]=0;
		}else{
			ans1[i]=1;
		}
	}
	int ans=0;
	for(int i=0;i<x;i++){
		int q=1;
		if(i==0){
			q=1;
		}else{
			for(int j=0;j<i;j++){
				q*=2;
			}
		}
		ans+=ans1[i]*q;
	}
	return ans;
}
int a[104859];
int long l[999999],l1=0;
int long r[999999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,o=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int ans=a[j];
			if(i==1){
				
			}else{
				for(int k1=j+1;k1<i+j;k1++){
					ans=cm(ans,a[k1]);
				}
			}
			if(ans==k){
				l[l1]=j;
				r[l1]=i+j-1;
				l1++;
			}
		}
	}
	if(l1==0){
		cout<<0;
	}else if(l1==1){
		cout<<1;
	}else{
		int la=0;
		for(int i=0;i<l1;i++){
			int oi[100000],oi1=0,sum=0;
			for(int k1=l[i];k1<=r[i];k1++){
				oi[oi1]=k1;
				oi1++;
			}
			for(int j=i+1;j<l1;j++){
				bool flag=1;
				int oi11[100000],oi111=0;
				for(int k1=l[j];k1<=r[j];k1++){
					oi11[oi111]=k1;
					oi111++;
				}
				for(int k1=0;k1<oi1;k1++){
					for(int k11=0;k11<oi111;k11++){
						if(oi[k1]==oi11[k11]){
							flag=0;
						}
					}
				}
				if(flag){
					sum++;
				}
			}
		if(sum>la){
			la=sum;
		}
	}
		if(la==0){
			cout<<1;
		}else if(k%2==0){
			cout<<la+1;
		}else{
			cout<<la;
		}
	}

	return 0;
} 
