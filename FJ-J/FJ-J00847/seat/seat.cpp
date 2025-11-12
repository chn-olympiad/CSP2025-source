#include<bits/stdc++.h>
using namespace std;
int n,m,sco[114],num,ann;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> sco[1];
	num=1;
	for(int i=2;i<=n*m;i++){
		cin >> sco[i];
		if(sco[i]>sco[1]){
			num++;
		}
	}
	ann = (num-1)/n+1;
	cout << ann << " ";
	if(ann%2==1){cout << num-(ann-1)*n;}
	if(ann%2==0){cout << ann*n-num+1;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




