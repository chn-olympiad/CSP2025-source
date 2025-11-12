#include <bits/stdc++.h>
using namespace std;
int t;
long long n,s = 0,d = 0,m = 0;
int a[2000] = {},b[2000] = {},c[2000] = {};
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i = 0;i<n;i++){
			s = max(a[i],a[i+1]);
			d = max(b[i+1],b[i+1]);
			m = max(c[i+1],c[i+1]);
			if(max(s,max(d,m)) == s){
				cout<<s+max(d,m);
				break;
			}else if(max(s,max(d,m)) == d){
				cout<<d+max(s,m);
				break;
			}else if(max(s,max(d,m)) == m){
				cout<<m+max(s,d);
				break;
			}
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
