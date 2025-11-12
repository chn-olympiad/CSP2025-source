#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;//nÁÐ,mÐÐ 
	cin >> n >> m;
	int a[n*m];
	cin >> a[0];
	int s=a[0];
	for(int i=1; i<n*m; i++){
		cin >> a[i];
	}
	int seatn=1,seatm=1;
	sort(a,a+n*m,cmd);
//	cout << s << endl;
//	for(int i=0; i<n*m; i++){
//		cout << a[i] << " ";
//	}
//	cout << endl;
	for(int i=0; i<n*m; i++){
		if(a[i]==s){
			if(n%2==0){
				printf("%d %d",seatn,(m-seatm));
				return 0;
			}
			printf("%d %d",seatn,seatm);
			return 0;
		}
		seatm++;
//		printf("%d  %d\n",i,seatm);
		if(seatm>m){
			seatn++;
			seatm=1;
//			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
