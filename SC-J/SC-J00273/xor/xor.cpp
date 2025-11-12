#include<bits/stdc++.h>
using namespace std;

const int N=6e5+10;

int a[N];
int s[N];
struct node {
	bool flag=1;
	int num;
	int he=1,ta=1;
} ai[N],aj[N];

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	s[1]=a[1],s[0]=0;
	for(int i=2; i<=n; i++) s[i]=s[i-1]^a[i];

//	for(int i=0; i<=n; i++) cout<<s[i]<<" ";
//	cout<<endl;

//	先考虑暴力

	int ans=0;
	int top1=1;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(i==j) {
				if(a[i]==k) {
//					cout<<i<<" "<<j<<endl;
					ai[top1].num=i;
					aj[top1].num=j;
					top1++;
					continue;
				}
			}
//			cout<<i<<" "<<j<<" "<<k<<endl;
			if(abs(s[j]-s[i-1])==k) {
//				cout<<i<<" "<<j<<endl;
				ai[top1].num=i;
				aj[top1].num=j;
				top1++;
			}
		}
	}
	top1--;
//	for(int i=1;i<=top1;i++){
//		cout<<ai[i].num<<" "<<aj[i].num<<" "<<ai[i].flag<<endl;
//	}
	for(int i=1; i<=top1; i++) { //判断包含关系，有包含关系的时候取小
		for(int j=1; j<=top1; j++) {
			if(i==j || ai[i].flag==0 || ai[j].flag==0) continue;
			if(ai[i].num<=ai[j].num && aj[i].num>=aj[j].num) {
				ai[i].flag=aj[i].flag=0;
				continue;
			}
		}
	}
	for(int i=1; i<=top1; i++) { //判断前一个的右端点是否与下一个的左端点有重合
		for(int j=top1; j<=top1; j++) {
			if(i==j || ai[i].flag==0 || ai[j].flag==0) continue;
			if(aj[i].num>=ai[j].num) {
				aj[i].ta=ai[j].he=0;
			}
		}
	}
	for(int i=1; i<=top1; i++) { //假如左端点右端点都有重合，那么直接舍弃
		if(ai[i].he==0 && aj[i].ta==0) {
			ai[i].flag=aj[i].flag=0;
		}
	}
//	for(int i=1; i<=top1; i++) {
//		cout<<ai[i].num<<" "<<aj[i].num<<" "<<ai[i].flag<<endl;
//	}
	for(int i=1; i<=top1; i++) {
		if(ai[i].flag==1) ans++;
	}
	cout<<ans;

	return 0;
}
/*
4 2
2 1 0 3
10 1 0 11
2 3 3 0

5 2
2 1 0 3 3
10 1 0 11 11
2 3 3 0 3


考虑前缀和
4 0
1 0 1 0

*/