#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int aee[100005];
int acc[100005];
int g;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		g=0;
		int a=0,b=0,c=0;
		for(int i = 1;i <= n;i++){
			cin >> arr[i] >> aee[i] >> acc[i];//输入各社团好感度 
		}
		
		for(int i = 1;i <= n;i++){
			int ar=arr[i];
			int ae=aee[i];
			int ac=acc[i];
			if(ar >= ae && ar >= ac){
				
				if(a+1 <= n / 2){
					a+=1;
					g += ar;
				}
				else{
					if(ae >= ac){
						if(b+1 <= n /2){
							b+=1;
							g += ae;
						}
						else{
							c+=1;
							g += ac;
						}
					}
					else{
						if(c+1 <= n / 2){
							c+=1;
							g += ac;
						}
						else{
							b+=1;
							g += ae;
						}
					}
				}
			}
			
			else if(ae >= ar && ae >= ac){
				
				if(b+1 <= n / 2){
					b+=1;
					g += ae;
				}
				else{
					if(ar >= ac){
						if(a+1 <= n / 2){
							a+=1;
							g += ar;
						}
						else{
							c+=1;
							g += ac;
						}
					}
					else{
						if(c+1 <= n / 2){
							c+=1;
							g += ac;
						}
						else{
							a+=1;
							g += ar;
						}
					}
				}	
			}
			
			
			else if(ac >= ar && ac >= ae){
				
				if(c+1 <= n / 2){
					c+=1;
					g += ac;
				}
				else{
					if(ar >= ae){
						if(a+1 <= n /2){
							a+=1;
							g += ar;
						}
						else{
							b+=1;
							g += ae;
						}
					}
					else{
						if(b+1 <= n / 2){
							b+=1;
							g += ae;
						}
						else{
							a+=1;
							g += ar;
						}
					}
				}	
			}
			
			
			
		}
		cout << g << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
