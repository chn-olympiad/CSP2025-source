#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int n=-1,m=-1,len=-1;
int S[10000]={0},Rs=-1;
int efcz(int s,int t){
	int l=0,r=t-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(S[mid]<s)r=mid-1;
		if(S[mid]>s)l=mid+1;
		if(S[mid]==s)return mid;
	}
	return -1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	int k=1,a[1000][1000];
	for(int i=0;i<n;i++){
		if(i%2==0)for(int j=0;j<m;j++)a[j][i]=k++;
		else for(int j=m-1;j>=0;j--)a[j][i]=k++;
	
	}
	for(int i=0;i<len;i++)cin>>S[i];
	Rs=S[0];
	sort(S,S+len,cmp);
	int side=efcz(Rs,len)+1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==side){
				printf("%d %d\n",j+1,i+1);
				return 0;
			}
		
		}
	}
}
