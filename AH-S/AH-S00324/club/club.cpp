#include<bits/stdc++.h>
using namespace std;
int s[100001],t[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c,n,ti;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>n;
		int sum=0;
		int y1=0,y2=0,y3=0;
		int x1,x2,x3;
		for(int j=1;j<=n;j++){
			cin>>x1>>x2>>x3;
			s[j]=max(max(x1,x2),x3);
			sum+=s[j];
			if(x1==s[j]){
				ti=max(x2,x3);
				t[j]=x1-ti;
				y1++;
			}
			else if(x2==s[j]){
				ti=max(x1,x3);
				t[j]=x2-ti;
				y2++;
			}
			else if(x3==s[j]){
				ti=max(x1,x2);
				t[j]=x3-ti;
				y3++;
			}
			for(int k=j;k>1;k--){
				if(t[k-1]>t[k])
				swap(t[k-1],t[k]);
			}
		}
		int num;
		num=max(max(y1,y2),y3);
		if(num<=n/2){
			cout<<sum<<endl;
		}
		else{
			int x;
			x=num-n/2;
			for(int z=1;z<=x;z++){
				sum-=t[z];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
