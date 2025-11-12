#include <bits/stdc++.h>
using namespace std;
int grade[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>grade[i];
	}
	int R=grade[1],xiaoR=0;
	sort(grade+1,grade+num+1);
	for(int i=1;i<=num;i++){
		if(grade[i]==R){
			xiaoR=num-i+1;
			break;
		}
	}
	int hang=xiaoR%n,lie=xiaoR/m;
	if(hang!=0) lie++;
	else hang=n;
	if(lie%2==1) cout<<lie<<' '<<hang;
	else cout<<lie<<' '<<n-hang+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 