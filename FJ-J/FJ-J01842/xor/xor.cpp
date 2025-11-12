#include<bits/stdc++.h>
using namespace std;
int n,k;
int zh(int a){
	int flag=0;
	stack<int> b;
	while(a!=0){
		b.push(a%2);
		a=(a-a%2)/2;
		flag++;
	}
	int c=0;
	for(int i=0;i<flag;i++){
		int sum=1;
		for(int j=0;j<flag-1;j++){
			sum*=10;
		}
		c=c+b.top()*sum;
		flag--;
		b.pop();
	}
	return c;
}
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int flag1=0,flag2=0;
	int bx[n];
	fin>>n>>k;
//	cin>>n>>k;
	int s[n],z[n];
	for(int i=0;i<n;i++){
		fin>>s[i];
//		cin>>s[i];
		if(s[i]==k){
			flag1++;
		}else{
			bx[flag2]=i;
			flag2++;
		}
		z[i]=zh(s[i]);
	}
	if(flag1==n){
		fout<<n;
//		cout<<n;
		return 0;
	}
	int left=-1,right=-1;
	for(int i=0;i<flag2;i++){
		if(bx[i]+1==bx[i+1]&&left==-1){
			left=bx[i];
			right=bx[i+1];
			continue;
		}
		if(bx[i]+1==bx[i+1]&&left!=-1){
			right=bx[i+1];
			continue;
		}
		if(bx[i]+1!=bx[i+1]&&left!=-1){
			int t=z[left];
			int yes=0;
			while(t!=zh(k)){
				if(left==right){
					yes=1;
					break;
				}
				t=t|z[left+1];
				left+=1;
			}
			if(yes!=1){
				flag1++;
			}
			yes=0;
		}
	}
//	cout<<flag1;
	fout<<flag1;
	fin.close();
	fout.close();
	return 0;
}
