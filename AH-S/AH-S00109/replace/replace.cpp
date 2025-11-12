#include<bits/stdc++.h>
using namespace std;
struct xy{
	string x,y;
}zu[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		cin>>zu[i].x>>zu[i].y;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			int t=0;
			while(a.find(zu[i].x,t)!=-1){
				int l=a.find(zu[i].x,t);
				string t1=a.substr(0,l);
				string t2=a.substr(l+zu[i].x.size(),a.size()-l-zu[i].x.size());
				string t3=t1+zu[i].y+t2;
				if(t3==b){
					cnt++;
				}
				t=l+1;
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
