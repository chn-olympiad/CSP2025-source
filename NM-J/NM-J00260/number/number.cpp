#include<iostream>
#include<string>
using namespace std;
//学了半年就来考这13玩意，不会了，摸鱼吧 
int maxed(int a[100]){
	int w = 0;
	for(int c=0;c < 100;c++){
		if(a[c]!=-1){
			if(a[w]<a[c]){
				w = c;
			}
		}
	}
	return w;
}
int number(char a){
	if(a=='0'){
		return 0;
	}
	else{
		if(a=='1'){
			return 1;
		}
		else{
			if(a=='2'){
				return 2;
			}
			else{
				if(a=='3'){
					return 3;
				}
				else{
					if(a=='4'){
						return 4;
					}
					else{
						if(a=='5'){
							return 5;
						}
						else{
							if(a=='6'){
								return 6;
							}
							else{
								if(a=='7'){
									return 7;
								}
								else{
									if(a=='8'){
										return 8;
									}
									else{
										if(a=='9'){
											return 9;
										}
										else{
											return -1;
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
int main(){
	freopen("number.in","r",stdin)
	freopen("number.in","w",stdout)
	string a;
	int lon = string.length(a);
	int c[lon];
	for(int p=0;p<100;p++){
		c[p]=0;
	}
	int o;
	cin>>a;
	for(int n=0;n<lon;n++){
		int m=0;
		if(number(a[n]) > -1){
			cout<<number(a[n])<<endl;
			c[m] = number(a[n]);
			m++;
		}
	}
	for(int q=0;q<lon;q++){
		o=o*10+c[maxed(c)];
		c[maxed(c)]=-1;
	}
	for(int p=0;p<100;p++){
		cout<<c[p]<<endl;
	}
	return -1;			
}	
	
	
