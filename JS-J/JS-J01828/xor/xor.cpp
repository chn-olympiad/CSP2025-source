#include<bits/stdc++.h>
using namespace std;
int a,k;
int b[500000];
int sumxor(int s,int e){
	int x=b[s];
	for(int i=s+1;i<e;i++){
		x=(x^b[i]);}
	return (x==k);}
int bfs(int start,int end){
	if(start==end-1)return b[start]==k;
	int cnt=sumxor(start,end);
	for(int i=start+1;i<end;i++){
		cnt=max(cnt,bfs(start,i)+bfs(i,end));}
	return cnt;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	for(int i=0;i<a;i++){
		cin>>b[i];}
	cout<<bfs(0,a);
    return 0;}
