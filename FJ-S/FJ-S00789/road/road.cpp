#include<bits/stdc++.h>
using namespace std;
int date(const int a){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for (int i=0;i<=a;i++){
		for(int j=0;j<=a;j++){
			for (int n=0;n<=a;n++){
				for (int i=0;i<=a;i++){
					for(int j=0;j<=a;j++){
						for (int n=0;n<=a;n++){
							for (int i=0;i<=a;i++){
								for(int j=0;j<=a;j++){
									for (int n=0;n<=a;n++){
										for (int i=0;i<=a;i++){
											for(int j=0;j<=a;j++){
												for (int n=0;n<=a;n++){
													cout<<100*i+10*j+n;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
 
int main(){
	date(2e100000);
	return 0;
}
