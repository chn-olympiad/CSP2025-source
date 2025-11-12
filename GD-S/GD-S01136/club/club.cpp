#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int t,n;
int a[100001][2];
int ap[100001][2];
int p[4];
int s[100001];
long long ans;
void f(){
	for(int i=1;i<n;i++)
	for(int j=1;j<n;j++){
		if(a[j][1]<a[j+1][1]){
			swap(a[j][1],a[j+1][1]);
			swap(a[j][0],a[j+1][0]);
			swap(ap[j][1],ap[j+1][1]);
			swap(ap[j][0],ap[j+1][0]);
		}
	}
}
void dfs(){
	p[3]=0;p[1]=0;p[2]=0;
	for(int i=1;i<=n;i++){
		if(p[ap[i][0]]<n/2){
			ans+=a[i][0];
			p[ap[i][0]]++;
		}
		else{
			ans+=a[i][0]-a[i][1];
			p[ap[i][1]]++;
		}
	}
}
int main(){
	ifstream fin("club.in");
	ofstream fout("club.out");
	fin>>t;
	while(t--){
		fin>>n;
		if(n<100000){
		int j,k,l;
		ans=0;
		for(int i=1;i<=n;i++){
			fin>>j>>k>>l;
			if(j>=k&&j>=l){
				a[i][0]=j;ap[i][0]=1;
				if(k>=l){
					a[i][1]=j-k;ap[i][1]=2;
				}
				else{
					a[i][1]=j-l;ap[i][1]=3;
				}
			}
			else if(k>=j&&k>=l){
				a[i][0]=k;ap[i][0]=2;
				if(j>=l){
					a[i][1]=k-j;ap[i][1]=1;
				}
				else{
					a[i][1]=k-l;ap[i][1]=3;
				}
			}
		else if(l>=k&&l>=j){
				a[i][0]=l;ap[i][0]=3;
				if(j>=k){
					a[i][1]=l-j;ap[i][1]=1;
				}
				else{
					a[i][1]=l-k;ap[i][1]=2;
				}
			}
		}
		f();
		dfs();
		fout<<ans<<endl;
	}
			else {
				ans=0;
				int j,k,l;
				for(int i=1;i<=n;i++){
				fin>>j>>k>>l;
				s[i]=max(max(j,k),l);
				}
				sort(s+1,s+n+1);
				for(int i=n;i>=n/2;i--){
					ans+=s[i];
				}
				fout<<ans<<endl;
			}
	}
	fin.close();
	fout.close();
	return 0;
}
