#include<bits/stdc++.h>
using namespace std;
int r,m,n,i=1,j=1;
int s[110];
bool f; //false为向上，true为向下 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i]; //所有人的分数 
    }
	r=s[0]; //小R的分数 
	sort(s+0,s+n*m); //排序（从小到大）
	for(int k=n*m-1;k>=0;k--){
		if(s[k]==r){
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		else{
			if(f) j--; //向上 
			else j++; //向下 
//	调试用	cout<<s[k]<<" "<<i<<" "<<j<<endl;
			if(j>n && !f){ //向下越界 
				i++; j=n;
				f=true;
			}
			else if(j<1 && f){ //向上越界 
				i++; j=1;
				f=false;
			}
		}
	} 
	return 0;
} 
