#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ma{
	string a;
	string b;
};
string replace_s(string, string, string);
ma l[200005];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string s;
	
	cin>>n>>q;
	for (int i = 0; i < n; i++)
	{
		cin>>l[i].a>>l[i].b;
	}
	
	for (int y = 0; y < q; y++)
	{
		string t, t2;
		int ans=0;
		cin>>t>>t2;
		int tsize = t.size(), t2size = t2.size();
		if(tsize != t2size){
			cout<<0<<endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			string aim;
			aim = replace_s(t, l[i].a, l[i].b);
			//cout<<aim<<endl<<endl;
			if(aim == t2){
				ans++;
				//cout<<ans<<endl;
			}
		}
		
		cout<<ans<<endl;
		//cout<<"end"<<endl;
	}
	
	
	return 0;
}

string replace_s(string a, string b, string c){
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j <= i; j ++){
			string ks;
			for(int k = j; k <= i;k ++){
				ks += a[k];
			}
			//cout<<ks<<endl<<endl;
			if(b == ks){
				
				string aim;
				for(int k = 0; k < j; k ++){
					aim += a[k];
				}
				aim += c;
				for(int k = i+1 ; k < size ; k ++){
					aim += a[k];
				}
				return aim;
			}
			
		}
	}
	return a;
}
