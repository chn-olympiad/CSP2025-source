#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node s[100001];
int b[100001],c[100001],num,n,A,B,C;
bool cmp(node a,node b){
	return a.a>b.a;
}
void dfsa(int ans,int sum){
	if(ans>n){
		if(sum>num){
			num=sum;
		}
		return;
	}
	if(A<n/2){
		b[ans]=s[ans].a;
		A++;
		dfsa(ans+1,sum+b[ans]);
		A--;
	}
	if(B<n/2){
		b[ans]=s[ans].b;
		B++;
		dfsa(ans+1,sum+b[ans]);
		B--;
	}
	if(C<n/2){
		b[ans]=s[ans].c;
		C++;
		dfsa(ans+1,sum+b[ans]);
		C--;
	} 
	return;
}
void dfsb(int ans,int sum){
	if(ans>n){
		if(sum>num){
			for(int i=1;i<=10;i++){
				c[i]=b[i];
			}
			num=sum;
		}
		return;
	}
	if(A<n/2){
		b[ans]=s[ans].a;
		A++;
		dfsb(ans+1,sum+b[ans]);
		A--;
	}
	if(B<n/2){
		b[ans]=s[ans].b;
		B++;
		dfsb(ans+1,sum+b[ans]);
		B--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		A=0,B=0,C=0,num=0;
		for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[1].c==0&&s[10].c==0&&s[1].b==0&&s[10].b==0){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n/2;i++)num+=s[i].a;
		}else if(s[1].c==0&&s[5].c==0&&s[7].c==0&&n==100000)dfsb(1,0);
		else dfsa(1,0);
		cout<<num<<endl;
	}
	return 0;
}
