#include <bits/stdc++.h>
using namespace std;
int a,b=0;
int num[101],wbqaityy[101];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	sort(num,num+a);
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			for(int t=0;t<a;t++){
				for(int w=0;w<a;w++){
					for(int p=0;p<a;p++){
						if(num[i]+num[j]+num[t]+num[w]+num[p]>num[a]*2){
							b++;
						}
					}
				}	
			}
		}
	}
	cout<<b;
	return 0;
}
