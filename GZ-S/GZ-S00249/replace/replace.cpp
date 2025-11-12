//GZ-S00249 贵州省黔西第一中学 杜仕壮 
#include<bits/stdc++.h>
using namespace std;
long long n,q,cnt;
char a[10000][10000][10000],b[10000][10000][10000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int j=0;j<q;j++){
		cin>>b[j][1]>>b[j][2];	
		}
		for(int j=0;j<q;j++){
			for(int i=0;i<n;i++){
			if(b.find(a[i][1])&&b.find(a[i][2]){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
