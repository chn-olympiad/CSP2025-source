//GZ-S00335 六盘水市第十三中学 王瑞希

#include<bits/stdc++.h>

using namespace std;
int a=0,n=0,b1,b2,b3,c1,c2,c3;
int a1[1000],a2[1000],a3[1000];
int main(){
	freopen("C:\\Users\\Administrator\\Desktop\\提高组\\GZ-S00335\\club\\club.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\提高组\\GZ-S00335\\club\\club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n;
		for(int k=0;k<n;k++){
			for(int p=0;p<a;p++){
				cin>>a1[p]>>a2[p]>>a3[p];
				b1++;
				b2++;
				b3++;
				if(b1<n/2 && b2<n/2 && b3<n/2){
					for(int y=0;y<=a;y++){
						if(a1[y-1]<a1[y]){
							c1=a1[y];
						}
					}
					for(int y=0;y<=a;y++){
						if(a2[y-1]<a2[y]){
							c2=a2[y];
						}
					}
					for(int y=0;y<=a;y++){
						if(a3[y-1]<a3[y]){
							c3=a3[y];
						}
					}
				}
			}
		}
		cout<<c1+c2+c3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
