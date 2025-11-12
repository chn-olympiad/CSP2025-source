#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string> s1(n);
	vector<string> s2(n);
	vector<string> q1(m);
	vector<string> q2(m);
	vector<int> sum(m,0);
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<m;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int f=q1[i].find(s1[j]);
			if(f+1){
				int l=0,s=0;
				string ss=q1[i];
				for(int k=f;k<f+s1[j].size();k++){
					ss[k]=s2[j][l];
					l++;
				}
				if(ss==q2[i]){
					sum[i]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
		cout<<sum[i]<<endl;
	return 0;
}
