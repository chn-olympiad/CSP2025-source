#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n,a[100005][4];
		int q1[50002],q2[10002],q3[50002];
		int top1=0,top2=0,top3=0,size1=0,size2=0,size3=0;
		int ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
	
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				q1[size1]=i;
				size1++; 
			}
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
				q2[size2]=i;
				size2++;
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][0]){
				q3[size3]=i;
				size3++;
			}
			
		}
		sort(q1,q1+size1,cmp);
		sort(q2,q2+size2,cmp);
		sort(q3,q3+size3,cmp);
		while(size1>n/2){
			if(a[q1[top1]][1]>a[q1[top1]][2]&&size2<n/2){
				q2[top2+size2]=q1[top1];
				size2++;
			}
			else{
				q3[top3+size3]=q1[top1];
				size3++;
			}
			size1--;
			top1++;
		}
		while(size2>n/2){
			if(a[q2[top2]][0]>a[q2[top2]][2]&&size1<n/2){
				q1[top1+size1]=q2[top2];
				size1++;
			}
			else{
				q3[top3+size3]=q2[top2];
				size3++;
				
			}
			size2--;
			top2++;
		}
		while(size3>n/2){
			if(a[q3[top3]][0]>a[q3[top3]][1]&&size1<n/2){
				q1[top1+size1]=q3[top3];
				size1++;
			}
			else{
				q2[top2+size2]=q3[top3];
				size2++;
			}
			size3--;
			top3++;
		}
		for(int i=top1;i<top1+size1;i++){
			ans+=a[q1[i]][0];
		}
		for(int i=top2;i<top2+size2;i++){
			ans+=a[q2[i]][1];
		}
		for(int i=top3;i<top3+size3;i++){
			ans+=a[q3[i]][2];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
