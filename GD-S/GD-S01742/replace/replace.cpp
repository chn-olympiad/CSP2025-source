#include<bits/stdc++.h>
using namespace std;
string a[200005][4];
string real[200005][2];
void huajian(int n){
	int k=0;
	while(real[n][0][k]==real[n][1][k]){
		k++;
	}
	int j=real[n][0].size()-1;
	while(real[n][0][j]==real[n][1][j]){
		j--;
	}
	for(int i=k;i<=j;i++){
		a[n][0]+=real[n][0][i];
		a[n][1]+=real[n][1][i];
		a[n][3]=k;
		a[n][4]=j;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string x,y;
	int n,q;
	cin>>n>>q;
	string aa,bb;
	int ans=0;
	bool xxx=1;
	for(int i=1;i<=n;i++){
		cin>>real[i][0]>>real[i][1];
		huajian(i);
	}
	for(int ii=0;ii<q;ii++){
		ans=0;
		cin>>real[0][0]>>real[0][1];
		huajian(0);
		for(int i=1;i<=n;i++){
			xxx=1;
			if(a[0][0]==a[i][0] and a[0][1]==a[i][1] and a[0][2]>=a[i][2] and real[0][0].size()-a[0][2]>=real[i][0].size-a[i][2]){
				for(int j=0;j<real[n][0].size();j++){
					if(real[0][0][a[0][2]-a[i][2]+i]!=real[i][0][j] or real[0][1][a[0][2]-a[i][2]+i]!=real[i][1][j]){
						xxx=0;
						break;
					}
				}
				if(xxx==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
