#include<bits/stdc++.h>
using namespace std;

int t,n,bnum; 
vector<vector<int> > a;
vector<int> pnum;
int pr[3];
int bj(int x){
	vector<int> minn(3,INT_MIN);
	vector<int> mini(3,-1);
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (minn[i]<a[x][j]){
				if (i==1 && mini[i-1]!=j){
					minn[i]=a[x][j];
					mini[i]=j;
				} else if (i==2 && mini[i-2]!=j && mini[i-1]!=j){
					minn[i]=a[x][j];
					mini[i]=j;
				}else if (i==0){
					minn[i]=a[x][j];
					mini[i]=j;
				}
			}
		}
	}
	if (pr[mini[0]]==bnum){
		if (pr[mini[1]]==bnum){
			return mini[2];
			
		}else{
			return mini[1];

		}
	}else{
		return mini[0]; 
		
	}
}
int main(){
	//Ò»Ûç 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){ 
		cin>>n;
		bnum=n/2;
		a=vector<vector<int> > (n,vector<int> (3,0));
		pnum=vector<int> (n,-1);
		for (int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			pnum[i]=bj(i);
			pr[pnum[i]]++;
		}
		int ans=0;
		for (int i=0;i<n;i++){
			ans+=a[i][pnum[i]];
		}
		cout<<ans<<endl;
	}
    return 0;
}

