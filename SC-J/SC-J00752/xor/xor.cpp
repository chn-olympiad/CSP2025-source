#include<bits/stdc++.h>
using namespace std;

int f(int n,int k,long long s[],int l){
	if(l>n) return 0;
	int a;
	int q[50005][2]={0};
	int p=0;
	for(int i=0;i<n-l+1;i++){
		if(l==1&&s[i]==k){
			a++;
			q[p][1]=i-1;
			q[p+1][0]=i+l;
			p++;
		}else if(l>1){
			int p=0;
			for(int u=0;u<l;u++) p^=s[i+u];
			if(p==k){
				a++;
				q[p][1]=i-1;
				q[p+1][0]=i+l;
				p++;
			}
		}
	}
	std::cout<<"~"<<a<<" "<<q[1][0]<<q[0][1]<<"~\n";
	int tmp=0;
	for(int i=0;i<p;i++){
		if(q[i][1]<q[i][0]){
			long long tp[50005]={0};
			for(int i=q[i][0];i<n;i++){
				tp[i-q[i][0]]=s[i];
			}
			tmp+=f(n-q[i][0],k,tp,l+1);
			continue;
		}
		long long tp[50005]={0};
		for(int i=q[i][0];i<q[i][1];i++){
			tp[i-q[i][0]]=s[i];
		}
		tmp+=f(n-q[i][0],k,tp,l+1);
	}
	return tmp+a;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	int n=0,k=0,u=0;
	long long a[50005];
	cin>>n>>k;
	int l=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) u++;
	}
	if(k==0){
		cout<<u/2;
		return 0;
	}else if(k==1){
		cout<<u;
		return 0;
	}
	std::cout<<f(n,k,a,1);
	return 0;
} 