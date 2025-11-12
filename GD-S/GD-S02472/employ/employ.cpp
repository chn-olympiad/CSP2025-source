#include<bits/stdc++.h>
using namespace std;
int n,m,a[550],cnt;
bool b[550];
string s;
int wy(int x){
	int w=1;
	for(int i=1;i<=x;i++)
		w*=i;
	return w;
}
void xx(int d,int k,int w){
	if(k==m){
		cnt+=wy(n-d+1);
		return;
	}
	if(d>n)
		return;
	
	
	for(int i=1;i<n;i++){
		if(w<a[i]&&b[i]==0){
			if(s[d-1]=='1'){
				b[i]=1;
				xx(d+1,k+1,w);
				b[i]=0;
			}if(s[d-1]=='0'){
				b[i]=1;
				xx(d+1,k,w+1);
				b[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xx(1,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
