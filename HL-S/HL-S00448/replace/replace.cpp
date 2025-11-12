#include<bits/stdc++.h>

using namespace std;

string s1[200005],s2[200005],t1[200005],t2[200005],ts[200005];
long long dif,difs[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		dif=0;
		long long num=0;
		cin>>t1[i]>>t2[i];
		for(int j=1;j<=n;j++){
			for(int k=0;k<t1[i].length();k++){
				if(t1[i].length()-k>=s1[j].length()){
					if(t1[i][k]==s1[j][0]){
						ts[i]=t1[i];
						for(int r=0;r<s1[j].length();r++){
							ts[i][k+r]=s2[j][r];
						}
						if(ts[i]==t2[i]) num++;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
