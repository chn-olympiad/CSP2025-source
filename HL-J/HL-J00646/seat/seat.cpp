#include <bits/stdc++.h>
using namespace std;
int student[110],me,number=1,c,r;
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> me;
	for(int i=1;i<105;i++){
		student[i];
	}
	for(int i=1;i<n*m;i++){
		int s;
		cin >> s;
		student[s]+=1;
	}
	for(int i=me;i<=100;i++){
		number+=student[i];
	}
	if(number%m==0){
		c=number/m;
	}
	else{
		c=number/m+1;
	}
	if(c%2==0){
		r=c*n-number+1;
	}
	else{
		r=number-(c-1)*n;
	}
	cout << c << ' ' << r;
	return 0;
}