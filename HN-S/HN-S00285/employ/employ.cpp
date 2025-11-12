#include<iostream>

using namespace std;

int n,m; 
char s[510];
int  c[510],p[510],cnt,pa;



int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> s[i];	
	}
	for(int i = 0;i < n;i++){
		cin >> c[i];
	}

	for(int i = 0;i < n;i++){
		if(c[i] != c[i+1]){
			pa++;
		}
	}
	for(int i = 0;i < n;i++){//难度难的配没耐心的人 难度低的配有耐心的人
		for(int j = 0;j < m;j++){
			if(s[i] - '0' == 1){
				if(pa > 0){
					cnt++;
				}
				pa--;
			}
		} 
	}
	
	cout <<  cnt << endl;
	
	
	return 0;
}
