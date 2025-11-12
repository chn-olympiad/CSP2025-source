#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s[110][110],minn=1000000;	
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		minn=min(a[i],minn);
	}
	int nm=n*m,x=a[1];
	if(minn==x){
		cout<<m<<" "<<n;
		return 0;
	}	
	sort(a,a+nm);
	int p=0,q=1;
	for(int i=nm;i>=1;i--){
		s[p][q]=a[i];
		if(s[p][q]==x){
			cout<<q<<" "<<p;
			return 0;
		}
		if(p==n&&q==m)return 0;	
		if(p==n&&q%2==1)q++;
		else if(p==1&&q%2==0)q++;
		else if(q%2==1)p++;
		else p--;	
	}	
	return 0;
}

