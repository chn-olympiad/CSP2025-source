#include<bits/stdc++.h>
using namespace std;
int a[1000010];
long long k=1,ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[k]=0;
			k++;
		}else{
			if(s[i]=='1'){
				a[k]=1;
				k++;
			}else{
				if(s[i]=='2'){
					a[k]=2;
					k++;
				}else{
					if(s[i]=='3'){
						a[k]=3;
						k++;
					}else{
						if(s[i]=='4'){
							a[k]=4;
							k++;
						}else{
							if(s[i]=='5'){
								a[k]=5;
								k++;
							}else{
								if(s[i]=='6'){
									a[k]=6;
									k++;
								}else{
									if(s[i]=='7'){
										a[k]=7;
										k++;
									}else{
										if(s[i]=='8'){
											a[k]=8;
											k++;
										}else{
											if(s[i]=='9'){
												a[k]=9;
												k++;
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
	sort(a+1,a+1+k);
	for(int i=k;i>1;i--){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
} 

