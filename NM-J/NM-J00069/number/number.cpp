#include <iostream>

int main()
{
std::string s;
std::cin>>s;
int a[100]=s;
int b[100];
int c=0;
for(int i=0;i<=s.strlen;i++){
if(a[i]<10){
b[c]=a[i];
c++;
}
}
while(1){
	int k=0;
for(int i=0;i<=s.strlen;i++){
	std::swap(b[i],b[i+1]);
	k++;
}if(k==0) {
	for(int i=0;i<=s.strlen;i++){
		std::cout<<b[i];
		break;}
	}
}
	return 0;
}
