//#include<iostream>
//#include<stdio.h>
//#include<bits/stl_algo.h>
#include<bits/stdc++.h>
using namespace std;
string c;
int w,a[114514],s;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>c;
	for(int i=0;i<c.size();i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[w]=c[i]-'0';
			w++;
		}
	}
	sort(a,a+w,cmp);
	for(int i=0;i<w;i++) cout<<a[i];
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
