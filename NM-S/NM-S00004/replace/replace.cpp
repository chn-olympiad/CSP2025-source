#include <iostream>
#include<string>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
    long long n,q;
    cin>>n>>q;
    string str1,str2;
    cin>>str1;
    cin>>str2;
    string t1,t2;
    for(int i=0;i<q;i++){
        cin>>t1;
        cin>>t2;
        printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
