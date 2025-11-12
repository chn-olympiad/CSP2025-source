
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cout<<1;
    string a;
    cin>>a;
    char letters[10086];
    int letter_number=0;
    int numbers[10086];
    int number_number=0;
    int i=0;
    for(int i=0;i<len[a];i++){
        if(int(a[i])<48 or int(a[i])>57){
            letters[letter_number]=a[i];
            letter_number+=1;
        }
        else{
            numbers[number_number]=int(a[i])-48;
            number_number+=1;
        }
        i+=1;

    }
    for(int i=0;i<letter_number;i++){\
        cout<<letters[i];

    }
    for(int i=0;i<number_number;i++){
        cout<<numbers[i];
        cout<<2;
    }


    return 0;
}
