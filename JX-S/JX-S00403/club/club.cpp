#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;

int t,n,tmn,a[MAXN][8];

bool isItTooMany(int id){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i][3]==id)cnt++;
	}
	if(cnt>n/2){tmn=cnt-(n/2);return true;}
	return false;
}

bool unityiitm(){
	return (isItTooMany(0)||
			isItTooMany(1)||
			isItTooMany(2));
}

int solveMyd(){
	int ret=0;
	for(int i=0;i<n;i++)
		ret+=a[i][a[i][3]];
	return ret;
}

void customSort(int id){
	for(int j=0;j<n;j++)
		for(int i=0;i<n-1;i++)
			if(a[i][id]>=a[i+1][id])
				swap(a[i],a[i+1]);
}

int main(){
	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);

	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxn=-1,maxi=0;
			if(a[i][0]>=maxn){maxn=a[i][0];maxi=0;}
			if(a[i][1]>=maxn){maxn=a[i][1];maxi=1;}
			if(a[i][2]>=maxn){maxn=a[i][2];maxi=2;}
			a[i][4]=maxi;
			a[i][3]=a[i][4];
			int minn=2147483647,mini=0;
			if(a[i][0]<=minn){minn=a[i][0];mini=0;}
			if(a[i][1]<=minn){minn=a[i][1];mini=1;}
			if(a[i][2]<=minn){minn=a[i][2];mini=2;}
			a[i][5]=mini;
			if(a[i][3]==0 && a[i][5]==1)a[i][6]=2;
			if(a[i][3]==0 && a[i][5]==2)a[i][6]=1;
			if(a[i][3]==1 && a[i][5]==2)a[i][6]=0;
		}
		if(unityiitm()){
			
				customSort(6);
				for(int i=0;i<tmn;i++)
					a[i][3]=a[i][6];
				while(unityiitm()){
					unityiitm();
					customSort(5);
					for(int i=0;i<tmn;i++)
						a[i][3]=a[i][5];
				}
			cout<<solveMyd();
		}else{
			cout<<solveMyd();
		}cout<<'\n';
	}
	return 0;
}