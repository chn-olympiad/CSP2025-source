#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[num]=s[i]-48;
			num++;
		}
		if(s[i+1]==' '){
			break;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
//290es1q0
//e d s  a j   4 j j  d   s b 42 a j s b d j a b j s 4 5 6 j  b d j a s b d j 2 3
//dskfssdsd1kbnjbhjb2kbkjbkjbkjb3hjbkjbhbh4jhbhjbhvvhgv5bhjbjhbhjbhjb6jbhjbkjbjkbnkjnbjkn7bjbjbkjbnjkbj8jbjkbjbjbjkbijbjkbkjbkjjbjk9jnbkjnkjnkbhvhjbvhjhjhjhjhjhjhjhjbhbhjhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh 0
