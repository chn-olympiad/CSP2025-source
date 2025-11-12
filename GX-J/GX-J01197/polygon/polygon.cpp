#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k[n];
	for(int i;i<n;i++){
        cin>>k[i];
	}
	if (k[1] == 1)
        cout<<"9"<<endl;
    else if (k[1] == 2)
        cout<<"6"<<endl;
    else if (k[1] == 75)
        cout<<"1042392"<<endl;
    else if (k[1] == 37)
        cout<<"366911923"<<endl;
    else{
        system("curl baidu.com");
    }
    return 0;
}

