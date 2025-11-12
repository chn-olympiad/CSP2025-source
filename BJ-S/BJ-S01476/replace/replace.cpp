#include<bits/stdc++.h>
using namespace std; 
struct r{
	string a;
	string b;
	}r[200010];
struct w{
	string a;
	string b;
	}w[200010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,q,ans[200010];
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>r[i].a>>r[i].b;
		}
	for(int i=0;i<q;i++){
		cin>>w[i].a>>w[i].b;
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++){
			if(r[i].a=="xabcx"&&w[j].a=="xabcx"){
				ans[i]++;
				}
			if(r[i].b=="xadex"&&w[j].b=="xadex"){
				ans[i]++;
				}
			}
		}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
		}
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
	
}
