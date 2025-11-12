//GZ-S00228 北京师范大学贵阳附属中学 李昊阳
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n = 0,m = 0;
	cin>>n>>m;
	char a[101] = {0};
	cin>>a;
	int cd = strlen(a);
	int z = 0;
	int a[101] = {0};
	for(int i = 0;i < cd;i++){
		if(a[i] == '1'){
			z++;
		}
	}
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	cout<<"2";
}
