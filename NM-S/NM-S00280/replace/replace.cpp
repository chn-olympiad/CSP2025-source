#include<bits/stdc++.h>
using namespace std;
int n,q,ans2=0;
string m[200005][2],r[200005][2];
int czth(string a,string b,string c,string d){
    int ans=0;
    for(int l=0;l<a.size();l++){
        for(int r=l+1;r<a.size();r++){
            bool cut=1;
            for(int i=l;i<r;i++){
                if(a[i]!=b[i]&&a[i]!=d[i]){
                    cut=0;
                }
            }if(cut==1){
                ans++;
            }
        }
    }
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>r[i][0];
	}for(int i=0;i<n;i++){
		cin>>m[i][0];
		cin>>m[i][1];
	}for(int i=0;i<q;i++){
        ans2=0;
        for(int j=0;j<n;j++){
            ans2+=czth(r[i][0],m[j][0],m[j][1],r[i][1]);
        }cout<<ans2<<endl;
    }
	return 0;
}