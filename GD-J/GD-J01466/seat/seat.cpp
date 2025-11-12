#include<bits/stdc++.h>
using namespace std;
struct mas{
	int scor;
	int num;
}N[105];
bool cmp(mas a,mas b){
	return a.scor>b.scor; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	
	int n,m;
	cin >> n >> m;
	int wpa=n*m;
	for(int i=1;i<=wpa;i++){
		cin >> N[i].scor;
		N[i].num=i;
	}
	sort(N+1,N+1+wpa,cmp);
	//cout << N[1].num << ' ' << N[2].num << '\n'; 
	int lie=1,hang=1,wei=1;
	while(1){
		if(N[wei].num==1){
			cout << lie << ' ' <<hang;
			return 0;
		}
		if(lie & 1){
			hang++;
			if(hang > m){
				hang=m;
				lie++;
			}
		}
		else{
			hang--;
			if(hang < 1){
				lie++;
				hang=1;
			}
		}
		wei++;
	}
	
	return 0;
}
