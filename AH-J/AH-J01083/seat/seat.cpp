#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105],bj;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) bj=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==bj){
			bj=i;
			break;
		}
	}
	//cout<<bj<<endl;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==bj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==bj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
共有 n × m 名考生
* n × m 名考生将按照 CSP-J 2025 第一轮的成绩, 由高到低蛇形分配
s 1 > s 2 > · · · > s n×m
成绩为 s 1 的考生的座位为 1,1
成绩为s n 的考生的座位为 1,n
成绩为s n+1 的考生的座位为第 2 列第n 行
成绩为s 2n 的考生的座位为2,1

em,i think it's maybe should use math
i will try


if R is s[x]
(x-1)/n+1  lie
hang maybe can bian li(er guo yu yan)

haha  bian li is true!!!










*/
