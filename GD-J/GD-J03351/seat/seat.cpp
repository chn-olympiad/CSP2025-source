#include <bits/stdc++.h>
using namespace std;
int n,m,a[1145],b[100][100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+len+1,cmp);
	int j=1,k=1;
	for(int i=1;i<=len;i++){
		b[j][k]=a[i];
		//cout<<"(ÐÐ)j = "<<j<<"  (ÁÐ)k = "<<k<<"\n";
		if(a[i]==x) cout<<k<<" "<<j<<endl;
		else if(k%2==0){
			j--;
		}
		else if(k%2==1){
			j++;
		}
		if(j==0&&i!=1){
			k++;j++;
		}
		else if(j==n+1){
			k++;j--;
		}
	}
	return 0;
} 
/*
2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
