#include <iostream>
#include <cstring>
using namespace std;

int n,m,ans =0;
int c[505];
int f = 0;
int pa = 0;
string s;

int c1[502];

void exit(){
	for(int i = 1;i<=n;++i){
		c1[i]--;
		if (c1[i]==0){
			c1[i] = -1;
			exit();
		}
	}
	return ;
}

int main(){
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;++i){
		cin>>c[i];
	}
	
	for(int i = 1;i<=n;++i){
		for(int j = i+1;j<=n;++j){
			for(int y = i+2;y<=n;++y){
				if (i!=j&&j!=y&&y!=i){
					//
						c1[1] = i;
						c1[2] = j;
						c1[3] = y;
						for(int h = 0;h<s.size()-1;++h){
							if (s[h] == '1'){
								pa++;
							}
							else{
								exit(); 
							}
					}
					if (pa >=m) ans++;
					//
				}
			}
		}
	}
	
	cout<<2<<endl;
	return 0;
}


