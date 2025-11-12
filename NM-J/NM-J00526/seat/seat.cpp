#include<iostream>
#include<algorithm>
//可以直接模拟因为n*m<=100 遍历即可
//也可以排序之后 令a=名次
//则有s=a/n   b=a-s*n;
//若s%2==0,答案为s,b,否则是s,n-b; 
//CSP-J2025 T2 ylqg
using namespace std;
bool sortde(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105]={0};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b = a[0];
	sort(a,a+(n*m),sortde);
	int count=0;
	for(int x=0;x<n;x++){
		if(x%2==0){
			for(int y=0;y<m;y++){
				if(a[count]==b){
					cout<<x+1<<' '<<y+1;
					return 0;
				}else{count++;}
			}
		}else{
			for(int y=m-1;y>=0;y--){
				if(a[count]==b){
					cout<<x+1<<' '<<y+1;
					return 0;
				}
				else{count++;}
			}
		}
		
	}
	return 0;
}
