#include <bits/stdc++.h>
using namespace std;
int n,m,a[12][12],b[106]; 
bool cmp(int a,int b){
	return a>b;
}
int chengji,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	cin >> chengji;
	b[1]=chengji;
	for (int i=2;i<=n*m;i++){
		cin >>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for (int i=1;i<=m;i++){
	    if (i%2)for (int j=1;j<=n;j++){
		    num++;
			a[j][i]=b[num];
	    }
	    else{
	    	for (int j=n;j>=1;j--){
	    		num++;
	    		a[j][i]=b[num];
			}
		}
    }
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=m;j++){
    		if (a[i][j]==chengji){
    			cout << j<<" "<<i;
			}
		}
	}
    //for (int i=1;i<=n;i++){
    //	for (int j=1;j<=m;j++){
    //		cout << a[i][j]<<" ";
	//	}
	//	cout <<endl;
	//}ต๗สิ 
	return 0;
} 
