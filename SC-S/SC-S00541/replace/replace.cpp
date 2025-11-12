#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}a[200005];
vector<int>b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		b[i].push_back(-1);
		for(int j=1,k=-1;j<(int)a[i].s1.size();j++){
			while(k>=0&&a[i].s1[k+1]!=a[i].s1[j])k=b[i][k];
			if(a[i].s1[k+1]==a[i].s1[j])k++;
			b[i].push_back(k);
		}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int c=0;
		for(int i=1;i<=n;i++){
			for(int j=0,k=-1;j<(int)t1.size();j++){
				while(k>=0&&a[i].s1[k+1]!=t1[j])k=b[i][k];
				if(a[i].s1[k+1]==t1[j])k++;
				if(k==(int)a[i].s1.size()-1){
					string t=t1;
					int cnt=0;
					for(int l=j;l>=j-k;l--,cnt++){
						t[l]=a[i].s2[a[i].s2.size()-1-cnt];
					}
					if(t==t2)c++;
					k=b[i][k];
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}