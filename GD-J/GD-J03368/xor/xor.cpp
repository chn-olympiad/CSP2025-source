#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],ans;
string bw(int a){
	int e=0,w=1;
	while(a!=0){
		e+=a%2*w;
		a/=2;
		w*=10;
	}
	string c=to_string(e);
	return c;
}
int yh(int a,int b){
	int zh=0;
	string c=bw(a);
	string d=bw(b);
	reverse(c.begin(),c.end());
	reverse(d.begin(),d.end());
	int w=1;
	for(int i=0;i<max(c.size(),d.size());i++){
		if(c[i]!=d[i]){
			zh+=1*w;
		}
		w*=2;
	}
	return zh;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ln=n;
	for(int i=1;i<=ln;i++){
		int sum=a[i];
		if(a[i]==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum=yh(sum,a[j]);
			if(sum==k){
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
