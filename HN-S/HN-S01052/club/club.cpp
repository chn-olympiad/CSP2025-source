#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+10;
struct Node{
	int one, two, thr;
}a[N];
bool cmp1(Node x, Node y){
	return (x.one!=y.one? x.one>y.one : (x.two!=y.two? x.two>y.two : x.thr>=y.thr));
}
bool cmp2(Node x, Node y){
	return (x.two!=y.two? x.two>y.two : (x.one!=y.one? x.one>y.one : x.thr>=y.thr));
}
bool cmp3(Node x, Node y){
	return (x.thr!=y.thr? x.thr>y.thr : (x.two!=y.two? x.two>y.two : x.one>=y.one));
}
int cheak(int k, int n){
	if(k==1) sort(a, a+n, cmp1);
	else if(k==2) sort(a, a+n, cmp2);
	else if(k==3) sort(a, a+n, cmp3);
	int sum=0;
	int flag2=0, flag3=0;
	for(int i=0; i<n; i++){
		if(k==1){
			if(i<n/2){
				sum+=a[i].one;
			}
			else{
				if(a[i].two>a[i].thr && flag2<n/2 || flag3>=n/2){
					sum+=a[i].two;
					flag2++;
				}
				else{
					sum+=a[i].thr;
					flag3++;
				}
			}
		}
		else if(k==2){
			if(i<n/2){
				sum+=a[i].two;
			}
			else{
				if(a[i].one>a[i].thr && flag2<n/2 || flag3>=n/2){
					sum+=a[i].one;
					flag2++;
				}
				else{
					sum+=a[i].thr;
					flag3++;
				}
			}
		}
		else if(k==3){
			if(i<n/2){
				sum+=a[i].thr;
			}
			else{
				if(a[i].one>a[i].two && flag2<n/2 || flag3>=n/2){
					sum+=a[i].one;
					flag2++;
				}
				else{
					sum+=a[i].two;
					flag3++;
				}
			}
		}
	}
	return sum;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d%d%d", &a[i].one, &a[i].two, &a[i].thr);
		}
		int sum1=cheak(1, n);
		int sum2=cheak(2, n);
		int sum3=cheak(3, n);
		printf("%d\n", max(sum1, max(sum2, sum3)));
	}
	//
	fclose(stdin);
	fclose(stdout);
	return 0;
}
