#include<bits/stdc++.h>
using namespace std;
int seat[11][11];
int score[101];
int b,k = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;++i){
		cin >> score[i];
	}
	b = score[1];
	for(int i = 1;i <= n*m;++i){
		if(b < score[i]){
			k++;
		}
	}
	int l = k,o = 1;
	while(l > 0){
		l-= n;
		if(l > 0){
			o++;
		}
	}
	if(o % 2){
		cout << o << " " << k - (o - 1) * n;
	}
	else{
		cout << o << " " << o * n - k + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

