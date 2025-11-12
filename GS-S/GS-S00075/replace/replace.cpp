#include<bits/stdc++.h>
using namespace std;

map<string,string>d;

int func(string a1,string a2){
	string x = "",y = "",z = "",y2 = "";
	int l,r;
	for(int i = 0;i<=a1.size();i++){
		if(a1[i] != a2[i]){
			l = i;
			break;
		}
	}
	for(int i = a1.size()-1;i>=0;i--){
		if(a1[i] != a2[i]){
			r = i;
			break;
		}
	}
	for(int i = 0;i<l;i++){
		x = a1[i]+x;
		
	}
	for(int i = l;i<=r;i++){
		y = y+a1[i];
		y2 = y+a1[i];
	}
	for(int i = r+1;i<a1.size();i++){
		z = z+a1[i];
	}
	int ans = 0;
//	cout<<x<<"\n";
//	cout<<y<<"\n";
//	cout<<z<<"\n";
//	cout<<"----------------\n";
//	cout<<y<<"\n";
	if(d[y] == y2){
		ans++;
	}
	for(int i = 0;i<x.size();i++){
		y = x[i]+y;
		y2 = x[i]+y2;
//		cout<<y<<"\n";
		if(d[y] == y2){
			ans++;
		}
		string y_ = y,y_2 = y2;
		for(int j = 0;j<z.size();j++){
			y_ = y_+z[j];
			y_2 = y_2+z[j];
//			cout<<y_<<"\n";
			if(d[y_] == y_2){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		string a1,a2;
		cin>>a1>>a2;
		d[a1] = a2;
	}
	int ans[200005];
	for(int i = 1;i<=q;i++){
		string qs1,qs2;
		cin>>qs1>>qs2;
		if(qs1.size() != qs2.size()){
			ans = 0;
		}else{
			ans[i] = func(qs1,qs2);
		}
	}
	for(int i = 1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
