#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct dog{
	string sa,sb;
}a[N];
bool check1(string x,string y){
	for(int i=0;i<y.size()-x.size();i++){
		if(x[i]==y[i]){
			for(int j=0;j<x.size();j++){
				if(x[j]==y[j]) return true;
			}
		}
	}
	return false;
}
bool check2(string x,string y){
	for(int i=0;i<y.size()-x.size();i++){
		if(x[i]==y[i]){
			for(int j=0;j<x.size();j++){
				if(x[j]==y[j]) return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].sa>>a[i].sb;
	}
	if(q==1){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		string c,b;
		cin>>c>>b;
		ans=0;
		for(int j=1;j<=n;j++){
			if(check1(a[j].sa,c) && check2(a[j].sb,b))
				ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	sfclose(stdout);
	return 0;
}
