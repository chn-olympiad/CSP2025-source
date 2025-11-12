#include<bits/stdc++.h>
using namespace std;
string a[100005][10];
long long n,q;
long long ans=0;
bool ex(long a,long b,string c,string d){
	for(int i=0;i<=c.size();i++){
		if(i>=a&&i<=b) continue;
		if(c[i]!=d[i]) return false;
	}return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i][1]>>a[i][2];
	for(int i=0;i<q;i++){
		string temp1,temp2;
		cin>>temp1>>temp2;
		for(int j=0;j<n;j++){
			if(temp1.find(a[j][1])==temp2.find(a[j][2])&&temp1.find(a[j][1])<=temp1.size()&&ex(temp1.find(a[j][1]),a[j][1].size(),temp1,temp2)) ans++;
		}cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
