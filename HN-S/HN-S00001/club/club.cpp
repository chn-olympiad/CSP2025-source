#include <bits/stdc++.h>
using namespace std;

long long storage[100005][4];
long long com[4];
long long em[10][100005][10];
long long anst[100005];
long long n[10];

bool smaller(long long a, long long b){
	return a<b;
}

int calcu(long long a[][10], long long b){
	long long ans=0, temp1=0,j=0;
	memset(storage, 0, sizeof(storage));
	memset(com, 0, sizeof(com));
	
	for(int i=1; i<=b; i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ans+=a[i][1];
			com[1]++;
			storage[i][1]=-1;
			storage[i][0]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			ans+=a[i][2];
			com[2]++;
			storage[i][2]=-1;
			storage[i][0]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
			ans+=a[i][3];
			com[3]++;
			storage[i][3]=-1;
			storage[i][0]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
		}
	}
	for(int i=1; i<=3; i++)
		if(com[i]>b/2)
			temp1=i;
	for(int i=1; i<=b; i++){
		if(storage[i][temp1]==-1){
			j++;
			anst[j]=storage[i][0];
		}	
	}
	sort(anst+1, anst+j+1, smaller);
	for(int i=1; i<=com[temp1]-b/2; i++)
		ans-=anst[i];
	return ans;
}


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int test;
	cin>>test;
	for(int i=1; i<=test; i++){
		cin>>n[i];
		for(int j=1; j<=n[i]; j++){
			for(int k=1; k<=3; k++){
				cin>>em[i][j][k];
			}
		}
	} 
	
	for(int i=1; i<=test; i++)
		cout<<calcu(em[i],n[i])<<endl;
	
	
	return 0;
}
