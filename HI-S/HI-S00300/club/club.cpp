#include <bits/stdc++.h>
using namespace std;
int a[100010][4];
int ma[100010];//存下标 0-2
int mid[100010];
int mi[100010];
int bm[4];//存人数 
int m;//限制 
int n;
int ans;
void solve(int x){
	bm[0]=0;
	bm[1]=0;
	bm[2]=0;
	int anss=0;
	for(int i=x;i<n;i++){
		if(bm[ma[i]]<m){
			bm[ma[i]]++;
			anss+=a[i][ma[i]];
		}else if(bm[mi[i]]<m){
			bm[mi[i]]++;
			anss+=a[i][mi[i]];
		}else{
			bm[mid[i]]++;
			anss+=a[i][mid[i]];
		}
	}
	for(int i=0;i<x;i++){
		if(bm[ma[i]]<m){
			bm[ma[i]]++;
			anss+=a[i][ma[i]];
		}else if(bm[mid[i]]<m){
			bm[mid[i]]++;
			anss+=a[i][mid[i]];
		}else{
			bm[mi[i]]++;
			anss+=a[i][mi[i]];
		}
	}
	//cout <<anss<<" !!!!!!!!!!!!!!"<<endl;
	if(anss>=ans){
		ans=anss;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		m=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int a1[3];
			a1[0]=a[i][0];
			a1[1]=a[i][1];
			a1[2]=a[i][2];
			sort(a1,a1+3);
			if(a1[0]==a[i][0]){
				mi[i]=0;
			}else if(a1[0]==a[i][1]){
				mi[i]=1;
			}else if(a1[0]==a[i][2]){
				mi[i]=2;
			}
			if(a1[1]==a[i][0]){
				mid[i]=0;
			}else if(a1[1]==a[i][1]){
				mid[i]=1;
			}else if(a1[1]==a[i][2]){
				mid[i]=2;
			}
			if(a1[2]==a[i][0]){
				ma[i]=0;
			}else if(a1[2]==a[i][1]){
				ma[i]=1;
			}else if(a1[2]==a[i][2]){
				ma[i]=2;
			}
			//cout <<ma[i]<<' '<<mid[i]<<' '<<mi[i]<<endl;
		}
		for(int x=0;x<n;x++){
			solve(x);
		}
		cout <<ans<<endl;
	}
	return 0;
}

