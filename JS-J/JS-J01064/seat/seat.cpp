#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int ccin;
	int littleR;
	for(int i=0; i<n*m;i++){
		if(i==0){cin>>littleR;
			a.push_back(littleR);
			continue;}
		cin>>ccin;
		a.push_back(ccin);
		}
	sort(a.begin(),a.end());
	int pai;
	for(int i=0;i<n*m;i++)if(a[i]==littleR)pai=i;
	pai=m*n-pai;
//out<<pai<<endl;
	int lie;
	lie=pai/(n)+1;
	if(pai%n==0)lie-=1;
	int hang;
	if(lie%2==0)hang=n-pai%(n+1);
	else hang=pai%(n) ;
	if(hang==0)hang=n;
	cout<<lie<<' '<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

