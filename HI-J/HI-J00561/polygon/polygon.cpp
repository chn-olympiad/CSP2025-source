#include<bits/stdc++.h>
using namespace std;
int a[5005],hj,n,b[5005],ans1=0;
int i1=1;
void gp(int t){
	//cout << ans1 << endl;
	if(t>n)return;
    for(int i=b[i1-1];i<=n;i++){	int sum=0,max1=0;
    	b[i1]=i;
    	i1++;
    	gp(t+1);
    	i1--;
		if(t>=3){
		int f=1;
		for(int j=1;j<=t;j++){
			if(j!=t){
				if(b[j]==b[j+1])f=0;
			}
	    	sum+=a[b[j]];
			if(a[b[j]]>max1){
				max1=a[b[j]];
			}
		}
		if(sum>max1*2&&f!=0){//cout << sum << " " << max1 << endl;
			//for(int j=1;j<=t;j++)cout << b[j] << " ";
		//cout << endl; 
		ans1++;
		}
	}   
	}
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n;i++)cin >> a[i];
	b[0]=1;
	gp(1);
	cout << ans1;
}  
