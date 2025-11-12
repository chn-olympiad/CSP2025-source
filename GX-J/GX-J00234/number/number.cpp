#include  <bits/stdc++.h>
using namespace std;

string a;
string ans;



int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    long long x=a.size();
    for(int i=0;i<x;i++){
	    if(a[i]<=57&&a[i]>=48){
			ans+=a[i];
		}
	}
    char q;
    long long y=ans.size();
	for(int j=0;j<y;j++){
		for(int i=0;i<y;i++){
		if(ans[i]<ans[i+1]){
			q=ans[i];
			ans[i]=ans[i+1];
			ans[i+1]=q;
			}
		}
		}

    cout<<ans;
return 0;
}
